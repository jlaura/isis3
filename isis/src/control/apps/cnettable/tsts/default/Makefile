APPNAME = cnettable

include $(ISISROOT)/make/isismake.tsts

commands:
	find $(INPUT)/*.cub > $(OUTPUT)/cubeList.lst; \
	$(APPNAME) FROMLIST=$(OUTPUT)/cubeList.lst \
	CNET=$(INPUT)/testNet.net \
	FLATFILE=$(OUTPUT)/cnetstats.txt \
        > /dev/null;
	rm -f $(OUTPUT)/cubeList.lst > /dev/null;
	cat $(OUTPUT)/cnetstats.txt | sed s/,\[^,]\*\.cub,/,file.cub,/ \
	  | sed 's/\([0-9][0-9]*\.[0-9]\)\([0-9][0-9]*\)/\1/g' \
	  | sed s/`date +%Y-%m-%dT`\[0-2\]\[0-9\]:\[0-5\]\[0-9\]:\[0-5\]\[0-9\]/date/ \
	  > $(OUTPUT)/output.txt
	rm -f $(OUTPUT)/cnetstats.txt > /dev/null;
	# To comment what is going on:
	# The 3 seds do as follows:
	# 1. remove cube filenames
	# 2. remove all but one digit of decimal numbers
	# 3. remove date and time
