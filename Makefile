RIGHTNOW = $(shell date +'%d/%m/%Y %H:%M:%S')

git:
	git add .
	git commit -m "$(RIGHTNOW)"
	git push

.PHONY: git
