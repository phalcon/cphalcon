%.c : %.y

remake:
	$(MAKE) clean
	$(MAKE) all
