# Benchmarks

This folder has the benchmarks for the Phalcon extension. Use them to compare two builds of the extension
(A/B): for example, the build before a change and the build after it.

## Method

- **Instruction counts are the main metric.** valgrind (cachegrind) counts the instructions that PHP
  executes. The count changes very little from run to run, also in a virtual machine.
- **Wall time is the second metric.** [PHPBench](https://phpbench.readthedocs.io/) measures it. Wall time
  changes with the load on the machine, so use it for large differences only.
- **Cold and warm counts.** `bin/instr` runs a subject 0, 1 and 1+k times:
  - `cold_ir = Ir(1) - Ir(0)`: the first call, with lazy setup.
  - `warm_ir = (Ir(1+k) - Ir(1)) / k`: one call after the first call.

  The process start, the extension start and the script compile cancel out.
- **Fixed conditions.** All runs use the same:
  - container (`cphalcon-bench-8.4`): no Xdebug, OPcache on for the CLI, JIT off, pinned PHP image
  - environment variables (`env -i`)
  - length of the path to the extension (a symlink with a fixed-length name)
  - build type: the release flags plus `-g`, stored in two files. Measurements use the file without debug
    information (under valgrind, debug information changes the count). Profiles use the file with it.
- **Each subject checks its result.** A subject throws an exception if the result is wrong. A fast result
  from a broken code path is not a gain.

## Requirements

- Docker with Docker Compose.
- The containers `cphalcon-dev-8.4` (compiles the extension) and `cphalcon-bench-8.4` (runs the benchmarks).
  The bench container starts only with the `bench` profile:

```bash
docker compose --profile bench up -d
```

The scripts expect the repository at `/srv` in the containers (the default mount).

## Build and store an extension

Compile in the dev container, then store the build with a label:

```bash
docker exec cphalcon-dev-8.4 tests/benchmarks/bin/build-so
docker exec cphalcon-dev-8.4 tests/benchmarks/bin/store-build <label>
```

- The build name is `<commit>-<label>`. `<commit>` is the last commit that changed `phalcon/` or `ext/`.
- Stored builds are in `.local/bench/so/` (not in git): `<name>.so` (for measurements), `<name>.debug.so`
  (for profiles) and `<name>.manifest` (flags, versions, checksums).
- `store-build` does not overwrite a stored build with a different one.
- Builds made with `ext/install` (or `cpl`) have no `-g`. Do not use them for benchmarks.

## Run

Wall time (PHPBench):

```bash
docker exec -e PHP_BENCH_BUILD=<build> cphalcon-bench-8.4 \
    vendor/bin/phpbench run --config=resources/phpbench.json --report=aggregate --tag=<tag>

docker exec -e PHP_BENCH_BUILD=<other-build> cphalcon-bench-8.4 \
    vendor/bin/phpbench run --config=resources/phpbench.json --report=aggregate --ref=<tag>
```

For wall time, stop the other containers first. They add noise.

Instruction counts:

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/instr <build> 'Phalcon\Tests\Benchmarks\Support\CollectionBench' benchGet
```

The result is in `.local/bench/out/instr/<build>/`.

Profile with file and line (callgrind):

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/php-bench --debug \
    --prefix "valgrind --tool=callgrind --vgdb=no --callgrind-out-file=/srv/.local/bench/out/profile.callgrind" \
    <build> tests/benchmarks/bin/subject.php 'Phalcon\Tests\Benchmarks\Support\CollectionBench' benchGet 000001000
docker exec cphalcon-bench-8.4 callgrind_annotate --auto=no --inclusive=yes /srv/.local/bench/out/profile.callgrind
```

## Write a benchmark

- One class for each area, in `tests/benchmarks/<Component>/<Name>Bench.php`, namespace
  `Phalcon\Tests\Benchmarks\<Component>`.
- Subject methods start with `bench`. Put the setup in a method named in `#[BeforeMethods(...)]`.
- Each subject checks its result and throws `RuntimeException` if it is wrong.
- `#[ParamProviders]` is not supported by `bin/instr`.
- The code style is the same as for the tests (phpcs, php-cs-fixer).

## Scripts

| Script             | Container | Purpose                                                               |
|--------------------|-----------|-----------------------------------------------------------------------|
| `bin/build-so`     | dev       | Compiles the extension with the release flags plus `-g`               |
| `bin/store-build`  | dev       | Stores the build in `.local/bench/so/` with a manifest                |
| `bin/php-bench`    | bench     | Runs PHP under fixed conditions (the only way to run PHP here)        |
| `bin/phpbench-php` | bench     | PHPBench runs this as its PHP binary; calls `php-bench`               |
| `bin/instr`        | bench     | Cold and warm instruction counts of one subject                       |
| `bin/subject.php`  | bench     | Runs one subject N times (`bin/instr` uses it)                        |
