import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;
    private JTextArea textArea;
    
    public String send(String request) {
        // Envoyer la requete au serveur
        try {
          request += "\n";  // ajouter le separateur de lignes
          output.write(request, 0, request.length());
          output.flush();
        }
        catch (java.io.IOException e) {
          System.err.println("Client: Couldn't send message: " + e);
          return null;
        }
        
        // Recuperer le resultat envoye par le serveur
        try {
          return input.readLine();
        }
        catch (java.io.IOException e) {
          System.err.println("Client: Couldn't receive message: " + e);
          return null;
        }
      }
    

    public MainFrame(String host, int port) throws UnknownHostException, IOException{
        // Connexion
        try {
            sock = new java.net.Socket(host, port);
          }
          catch (java.net.UnknownHostException e) {
            System.err.println("Client: Couldn't find host "+host+":"+port);
            throw e;
          }
          catch (java.io.IOException e) {
            System.err.println("Client: Couldn't reach host "+host+":"+port);
            throw e;
          }
          
          try {
            input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
          }
          catch (java.io.IOException e) {
            System.err.println("Client: Couldn't open input or output streams");
            throw e;
          }
        
        // Interface graphique
        setTitle("Interface");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Création de la zone de texte avec JScrollPane
        textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);
        
        // Création des actions
        Action actionButton1 = new AbstractAction("Bouton 1") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Texte du Bouton 1\n");
            }
        };

        Action actionButton2 = new AbstractAction("Bouton 2") {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.append("Texte du Bouton 2\n");
            }
        };

        Action actionExit = new AbstractAction("Quitter") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };
        
        // Toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.add(new JButton(actionButton1));
        toolBar.add(new JButton(actionButton2));
        toolBar.add(new JButton(actionExit));
        toolBar.setFloatable(false);
        
        // Menu
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Fichier");
        setJMenuBar(menuBar);
        menuBar.add(menu);
        menu.add(new JMenuItem(actionButton1));
        menu.add(new JMenuItem(actionButton2));
        menu.add(new JMenuItem(actionExit));
        
        // Ajout des composants à la fenêtre
        add(scrollPane, BorderLayout.CENTER);
        add(toolBar, BorderLayout.NORTH);
        
        // Pack et rend visible la fenêtre
        pack();
        setVisible(true);
    }
    
    public static void main(String argv[]) {
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >=1) host = argv[0];
        if (argv.length >=2) port = Integer.parseInt(argv[1]);
        
        MainFrame client = null;
        
        try {
          client = new MainFrame(host, port);
        }
        catch (Exception e) {
          System.err.println("Client: Couldn't connect to "+host+":"+port);
          System.exit(1);
        }
        
        System.out.println("Client connected to "+host+":"+port);
    
        // pour lire depuis la console
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        
        while (true) {
          System.out.print("Request: ");
          try {
            String request = cin.readLine();
            String response = client.send(request);
            System.out.println("Response: " + response);
          }
          catch (java.io.IOException e) {
            System.err.println("Client: IO error");
            return;
          }
        }
      }
}
