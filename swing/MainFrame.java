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
        
        // Création des boutons
        JButton button1 = new JButton("Bouton 1");
        JButton button2 = new JButton("Bouton 2");
        JButton exitButton = new JButton("Quitter");
        
        // Ajout des écouteurs d'événements aux boutons
        button1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textArea.append("Texte du Bouton 1\n");
            }
        });
        button2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                textArea.append("Texte du Bouton 2\n");
            }
        
        });
        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        
        // Création du panneau pour les boutons
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(exitButton);
        
        // Ajout des composants à la fenêtre
        add(scrollPane, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
        
        // Pack et rend visible la fenêtre
        pack();
        setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e) {
        // Récupérer la source de l'événement
        JButton button = (JButton)e.getSource();
        
        // Ajouter du texte à la zone de texte en fonction du bouton
        if (button.getText().equals("Bouton 1")) {
            textArea.append("Texte du Bouton 1\n");
        } else if (button.getText().equals("Bouton 2")) {
            textArea.append("Texte du Bouton 2\n");
        }
    }
    
    public static void main(String[] args) {
        new MainFrame();
    }
}
