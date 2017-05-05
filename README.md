# fanagen
Fantasy name generator

A little program made for fun; given the user's first name, outputs their epic name, suitable for role playing games and epic fantasy stories.

Όνομα: FaNaGen.

Είσοδος: Το μικρό όνομα (fname) του χρήστη.

Έξοδος: Όνομα (epic name => ename) που ταιριάζει σε παιχνίδια ρόλων και ιστορίες επικής φαντασίας.

Επεξεργασία:
 Ο χρήστης εισάγει το fname του. Στη συνέχεια αυτό χρησιμοποιείται ως βάση για την παραγωγή του ename. H διαδικασία έχει ως εξής:

•	Τα σύμφωνα του fname μένουν αμετάβλητα. (εκτός της περίπτωσης που περιγράφεται στην τελευταία κουκκίδα.)
•	Ένα σύμφωνο μπορεί (μπορεί και όχι) να ταιριάξει δίπλα σε κάποιο άλλο σύμφωνο σύμφωνα με τους αυτοσχέδιους κανόνες γειτνίασης συμφώνων.
•	Τα φωνήεντα αντικαθίστανται από συλλαβές φωνηέντων. Μπορεί να προστεθεί και κάποιο σύμφωνο, αν αυτό ταιριάζει με το επόμενο (διαδοχικό) σύμφωνο του fname, σύμφωνα με τους κανόνες γειτνίασης συμφώνων και αν δεν έπονται 2 συνεχόμενα σύμφωνα.
•	Τα γράμματα ή οι συλλαβές που θα διαμορφώσουν το ename, επιλέγονται με τυχαίο τρόπο.
•	Το τέλος της λέξης αντικαθίσταται από μια κατάληξη το πολύ 4 χαρακτήρων, της οποίας η κατασκευή συνοψίζεται παρακάτω.

Αλγόριθμος Εκτέλεσης:

	Δώσε fname.

	Μέχρι να φτάσεις στο τέλος του fname, κάνε:

	Αν το γράμμα είναι σύμφωνο:
	
		Τοποθέτησέ το στο ename.
		
		Αν το επόμενο και το προηγούμενο του τρέχοντος γράμματος 		είναι φωνήεντα:
		
			Με κάποια πιθανότητα, επέλεξε κάποιο σύμφωνο που να 			ταιριάζει με αυτό που τοποθετήθηκε, σύμφωνα με τους 			κανόνες γειτνίασης συμφώνων. Τοποθέτησέ το στο ename.
			
	Αλλιώς αν το γράμμα είναι φωνήεν:
	
		Επέλεξε τυχαία κάποια συλλαβή φωνηέντων, και αντικατέστησε 		το προαναφερθέν φωνήεν με αυτήν.
		
			Με κάποια πιθανότητα, επέλεξε και τοποθέτησε κάποιο σύμφωνο 		αμέσως μετά τη συλλαβή φωνηέντων, (σύμφωνα με τους κανόνες 		γειτνίασης συμφώνων) αν δεν έπονται 2 συνεχόμενα σύμφωνα 		στο fname.
			
	Κατασκεύασε την κατάληξη και ενσωμάτωσέ την στο ename.

	Εκτύπωσε το ename.


Κανόνες Γειτνίασης Συμφώνων:
 b -> !(f | j | p | q | s | x)

 c -> !(g | j | q | s | x | z)

 d -> !(c | q | s | t | x)

 f -> !(v | x)

 g -> !(c | j | k | q | x)

 h -> !(c | g | k | q | s | w | x | z)

 j -> !(c | d | g | s | t | w | x | z)

 k -> !(c | g | j | q | w | x)

 l -> *

 m -> !(x)

 n -> !(x)
 
 p -> !(b | f | m | x)

 q -> u (ΠΡΟΣΟΧΗ! There's not a 'q' without a 'u'.)

 r -> !(x)

 s -> !(j | x | z)

 t -> !(c | d | j | x)

 v -> !(c | f | j | w | x)

 w -> h

 x -> !(h | j | s | t | z)

 z -> !(c | j | s | x)

 English consonants:
 b c d f g h j k l m n p q r s t v w x z

Μονές ή Διπλές Συλλαβές Φωνηέντων:
a, e, i, o, u, y, aa, ae, ai, ao, au, ay, ee, ea, ei, eo, eu, ey, ia, ie, io, iu, oo, oa, oe, oi, ou, oy, ua, ue, ui, uo, uy, ya, ye, yo

Καταλήξεις:
 Οι καταλήξεις αποτελούνται από δύο τμήματα:
•	Το τμήμα φωνηέντων, που αντιστοιχεί σε μια συλλαβή φωνηέντων.(μονή ή διπλή)
•	Το τμήμα συμφώνων που αντιστοιχεί σε κάποιο από τα παρακάτω σύμφωνα ή συνδυασμούς συμφώνων:

	f, g, k, l, m, n, p, ph, r, s, t, th, x, z

 Τα δυο παραπάνω τμήματα θα ενωθούν για να κατασκευάσουν την κατάληξη. Στη συνέχεια, η κατάληξη θα αντικαταστήσει τα τελευταία x γράμματα του fname, όπου x = |κατάληξη|. (πλήθος σε χαρακτήρες)


Καστρινάκης Δημήτριος, Ιούλιος 2008
Τμήμα Επιστήμης Υπολογιστών
Πανεπιστήμιο Κρήτης

