{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [ cmake gcc clang-tools clang valgrind ];
  buildInputs = with pkgs; [
    cowsay
  ];
  env = {
    TEST="Hello there...";
    alias home="cd ~/code/nt/cpp/paystation"
  };
  shellHook = ''
    cowsay $TEST
  '';
}
