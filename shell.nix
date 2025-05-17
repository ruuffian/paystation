{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ cmake gcc clang-tools clang valgrind gdb ];
  buildInputs = with pkgs; [
    cowsay
  ];
  env = {
    TEST="Hello there...";
    PROJ_HOME="~/code/dev/paystation";
  };
  shellHook = ''
    alias home="cd $PROJ_HOME"
    cowsay $TEST
  '';
}
