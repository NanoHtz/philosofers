#!/usr/bin/env bash
set -u
N="${1:-50}"
ARGS="5 800 200 200 7"
mkdir -p runs
pass=0; fail=0
for i in $(seq 1 "$N"); do
  out="runs/must7_${i}.out"
  dbg="runs/must7_${i}.dbg"
  PHILO_DEBUG=1 ./philo $ARGS >"$out" 2>"$dbg"
  ec=$?
  if [ $ec -eq 0 ] && ! grep -q 'died' "$out"; then
    printf "%02d  PASS\n" "$i"
    pass=$((pass+1))
  else
    printf "%02d  FAIL  ec=%d  last_out=\"%s\"\n" "$i" "$ec" "$(tail -1 "$out" 2>/dev/null || echo "empty")"
    fail=$((fail+1))
  fi
done
echo "Summary: $pass/$N pass, $fail/$N fail"
echo "Para depurar un FAIL: tail -n 30 runs/must7_<idx>.dbg"
