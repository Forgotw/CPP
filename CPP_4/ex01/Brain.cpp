/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:16:33 by lsohler           #+#    #+#             */
/*   Updated: 2024/02/02 12:34:00 by lsohler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string baseIdeas[100] = {
	"Je veux jouer avec mes amis.",
	"Il est temps de faire une sieste.",
	"Où est ma nourriture?",
	"Les humains sont étranges.",
	"J'aimerais attraper ce papillon.",
	"Pourquoi l'herbe est-elle si verte?",
	"Les oiseaux chantent si joliment.",
	"Les câlins sont les meilleurs.",
	"Je suis curieux de ce qu'il y a derrière cette porte.",
	"Quand est-ce que nous allons à la plage?",
	"Les étoiles sont fascinantes la nuit.",
	"C'est amusant de sauter dans les flaques d'eau.",
	"Que se passe-t-il si je grimpe à cet arbre?",
	"Les souris sont-elles vraiment effrayantes?",
	"Chasser ma queue est un excellent exercice.",
	"Je suis le roi de la jungle... ou du moins de ce salon.",
	"Un jour, je pourrais attraper cette queue lumineuse.",
	"Pourquoi les humains parlent-ils tant?",
	"Les vétérinaires sont-ils nos amis ou nos ennemis?",
	"C'est génial de se rouler dans l'herbe fraîche.",
	"Je me demande ce que ressent un poisson dans l'eau.",
	"Les carottes sont-elles vraiment bonnes pour la vue?",
	"Les chiens et les chats peuvent-ils être meilleurs amis?",
	"L'herbe est-elle plus verte de l'autre côté de la clôture?",
	"Les oiseaux migrateurs ont-ils des cartes?",
	"Je suis le maître de la cachette parfaite.",
	"Pourquoi les chats aiment-ils les boîtes?",
	"Les miroirs sont-ils une autre dimension?",
	"Les écureuils sont-ils des experts en parkour?",
	"Les poissons se moquent-ils des bulles?",
	"Le ronronnement a-t-il des pouvoirs apaisants?",
	"Est-ce que les oiseaux aiment les chansons d'oiseaux?",
	"Les pingouins ont-ils des réunions secrètes?",
	"Le soleil est-il une boule de laine chaude dans le ciel?",
	"Les corbeaux sont-ils des oiseaux espions?",
	"Qu'est-ce que ça fait d'avoir des ailes?",
	"Les fourmis sont-elles toujours en retard?",
	"Pourquoi les écureuils traversent-ils la route?",
	"La pluie est-elle le chagrin du ciel?",
	"Les grenouilles aiment-elles les soirées karaoké?",
	"À quoi pensent les girafes tout là-haut?",
	"Est-ce que les abeilles font du miel en chantant?",
	"Pourquoi les hamsters font-ils de la roue toute la nuit?",
	"Les kangourous font-ils du saut à l'élastique?",
	"Pourquoi les chauves-souris sont-elles nocturnes?",
	"Les lézards prennent-ils des bains de soleil pour bronzer?",
	"Les éléphants se rappellent-ils toujours?",
	"Qu'est-ce que ça fait de voler comme un aigle?",
	"Les chèvres sont-elles des acrobates de montagne?",
	"Les moustiques ont-ils des réunions pour planifier leurs attaques?",
	"Les tortues aiment-elles les courses lentes?",
	"Les papillons sont-ils des fleurs qui volent?",
	"Les hérissons ont-ils des aiguilles de rechange?",
	"Pourquoi les chiens adorent-ils les promenades en laisse?",
	"Les poissons-globes sont-ils des maîtres du ballon?",
	"Les chiens comprennent-ils le concept du temps?",
	"Les lapins ont-ils des rêves de carottes?",
	"Les mouches savent-elles voler en formation?",
	"Les pingouins portent-ils des smokings pour des occasions spéciales?",
	"Les renards organisent-ils des soirées de camouflage?",
	"Les lions sont-ils des rois du sommeil?",
	"Les mouettes ont-elles un sens de l'humour?",
	"Les rennes aident-ils vraiment le Père Noël?",
	"Les serpents jouent-ils à cache-cache?",
	"Les koalas sont-ils des experts en sieste?",
	"Les chevaux rêvent-ils de galoper dans les prairies?",
	"Les pandas ont-ils des réunions pour discuter du bambou?",
	"Les singes aiment-ils les puzzles?",
	"Les cygnes pensent-ils qu'ils sont les meilleurs nageurs?",
	"Les loups hurlent-ils pour chanter?",
	"Les chameaux ont-ils une bosse pour le confort?",
	"Les araignées tissent-elles des histoires dans leurs toiles?",
	"Les canards discutent-ils de politique au parc?",
	"Les escargots ont-ils des courses d'escargots?",
	"Les écureuils sont-ils des collectionneurs de noix?",
	"Les grenouilles sont-elles des amateurs de cuisine à la vapeur?",
	"Les hiboux sont-ils de grands penseurs?",
	"Les pingouins sont-ils des experts en danse?",
	"Les chauves-souris font-elles du yoga dans les grottes?",
	"Les chats ont-ils des rêves de chasses épiques?",
	"Les chiens sont-ils les meilleurs amis des chats?",
	"Les dauphins jouent-ils à cache-cache avec les vagues?",
	"Les gorilles sont-ils de grands stratèges?",
	"Les kangourous font-ils du saut à l'élastique dans la nature?",
	"Les lions organisent-ils des réunions de chasse?",
	"Les loups se racontent-ils des histoires autour du feu?",
	"Les pingouins font-ils des concours de plongeon?",
	"Les poissons dorment-ils la nuit?",
	"Les renards ont-ils des rêves rusés?",
	"Les singes sont-ils des fans de Tarzan?",
	"Les tortues participent-elles à des courses de lenteur?",
	"Les éléphants sont-ils des amateurs de bains de boue?",
	"Les girafes ont-elles des hauteurs vertigineuses?",
	"Les hippopotames aiment-ils les bains de boue?",
	"Les kangourous organisent-ils des compétitions de saut?",
	"Les koalas sont-ils des experts en câlins?",
	"Les lions se considèrent-ils comme les rois de la jungle?",
	"Les moutons comptent-ils les humains pour s'endormir?",
	"Les pingouins aiment-ils les soirées dansantes sur la glace?",
	"Les renards jouent-ils à cache-cache dans la forêt?"
};

Brain::Brain() {
	for(int i = 0; i < 100; i++) {
		this->ideas[i] = baseIdeas[i];
	}
	std::cout << "Brain: Default Constructor called." << std::endl;
}

Brain::Brain(Brain const &other) {
	*this = other;
	std::cout << "Brain: Copy Constructor called." << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain: Default Destructor called." << std::endl;

}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "Brain: Operator Constructor called." << std::endl;
	if (this != &other) {
		*this = other;
	}
	return(*this);
}

void	Brain::think(void) {
	int	index = std::rand() % 100;
	std::cout <<  YELLOW << this->ideas[index] << RESET << std::endl;
}

std::string Brain::getIdeas(int i) {
	return (this->ideas[i]);
}

void	Brain::setIdeas(std::string idea, int i) {
	this->ideas[i] = idea;
}

void	Brain::resetIdeas(void) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "My brain is emtpy";
	}
}
