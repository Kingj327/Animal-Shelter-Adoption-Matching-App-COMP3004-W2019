Database is implemented.
Animal profiles (6) are created from database.
Note (for those doing View Animal) that in animal.h, there are 2 constant strings holding all
    the attributes and their respective options. There is also an animal.toString() method. It
    shouldn't be too difficult to realize that the non-physical attributes are stored in the
    database as integers 0-2, and the corresponding options are stored in the nonphys constant's
    inner list in positions 1-3. To view the animals, its really just have a textEdit field with
    the attribute name (index 0), and then have a lineEdit (or dropdown box with the 3 options)
    set with a default value set to the string at index 1-3 (depending on the value from the
    database)
Note still trying to figure out how to switch between screens. For now feel free to delete the
    querying stuff (on the UI) and work with that.





Checklist:

FIRST THINGS FIRST (Complete):
(X) Use "queryAndSave" to save animal information to internal variable upon loading database.
(X) Use the above variable to update animal information in animal class.
        (X) Update id and name
        (X) Update phys attributes
        (X) Update non-phys attributes




Database (Complete):
(X) Figure out how to query the database
(X) Figure out how to load stuff from the database to the textbox on the main window
(X) Store queried data in variables in the StorageDatabase class
        (X) Create Animal class instances from that stored data, then delete the data? prob not.
                NOTE: Data isn't currently being deleted. Will be usd later.
( ) Delete any temp data values and change the database object to use mainly pointersS

Animal:
(X) Create the animal class from the database information
( ) Create the ability to add animals.
        ( ) ...to the application (object)
        ( ) ...to the database (from the animal object creation)
( ) Create the ability to remove animals. (OPTIONAL for D1)
        ( ) ...from the application (object)
        ( ) ...from the database (from the animal object upon deletion)
( ) Create the view animals feature

Navigation:
(X) Figure out how to click on a widget and change the screen
( ) Add 4 different basic screens:
        (X) Login,
        (X) Querying (for testing),
        ( ) Add animal
        ( ) View animal

Login:
(X) Create a way to log in to the system
(X) Add a simple UI without going GUI crazy. (2 textfields, 2 lineEdits, and a button)

Attributes (optional):
( ) Non Physical:
        - Loyal -> loyalty


NOTES/QUESTIONS:
- Would it make more sense to have the animal class hold pointers to the database variables or
  should they have their own variables. On one hand, it's safer to have the animal class hold
  its own variables so we can't accidently change the database. On the other hand, its slightly
  more work to update the database now, and it doubles the usage of storage. Opposite for if we had
  the animal class just point to the database variables.
- We're working off one main screen right now called MainWindow. The likely approach in the future
  (im assuming) would be to use multiple widgets to create different screens. For now, I guess
  we'll keep using the MainWindow.
