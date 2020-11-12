FROM gcc:10.2.0

COPY . .
RUN make

ENTRYPOINT ["./masolve"]
CMD ["example"]
