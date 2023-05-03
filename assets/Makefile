UML=plantuml

SOURCES = $(shell find . -name "*.plantuml")
PNG = $(SOURCES:.plantuml=.png)

all: $(PNG)

%.png: %.plantuml
		$(UML) $<

clean:
	rm -f $(PNG)
