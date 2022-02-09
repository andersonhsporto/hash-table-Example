CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

clean:
	rm -rf a.out

push:clean
	rm -rf push_swap
	git add .
	read -p "Message: " message; \
	git commit -m "$$message"; \
	git push