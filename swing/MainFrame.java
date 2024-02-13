import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    
    public MainFrame() {
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
    
    public static void main(String[] args) {
        new MainFrame();
    }
}
