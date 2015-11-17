
JFLAGS = -cp
JC = javac
PROG = SetTopBox

.SUFFIXES: .java .class
.java.class:
		$(JC) $(JFLAGS) inf224/orube *.java

CLASSES = \
		SetTopBox.java \
		Client.java 
		
default: classes
	
all: classes

classes: $(CLASSES:.java=.class)

clean:
		$(RM) *.class

run: all
		java inf224.orube.${PROG}
