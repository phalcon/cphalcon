# Benchmarks

This folder has the benchmarks for the Phalcon extension. Use them to compare two builds of the extension
(A/B): for example, the build before a change and the build after it.

## Method

- **Instruction counts are the main metric.** valgrind (cachegrind) counts the instructions that PHP
  executes. The count changes very little from run to run, also in a virtual machine.
- **Wall time is the second metric.** [PHPBench](https://phpbench.readthedocs.io/) measures it. Wall time
  changes with the load on the machine, so use it for large differences only.
- **Cold and warm counts.** `bin/instr` runs a subject one time without valgrind (a warm-up, so that file
  caches exist), then 0, 1 and 1+k times under valgrind:
  - `cold_ir = Ir(1) - Ir(0)`: the first call, with lazy setup.
  - `warm_ir = (Ir(1+k) - Ir(1)) / k`: one call after the first call.

  The process start, the extension start and the script compile cancel out.
- **Main number: `warm_ir`.** Compare builds with `warm_ir`: it has no script compile and no regex compile in
  it. `cold_ir` is the second number (first-call and lazy-setup effects). A php-fpm run is the final check.
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

## Micro subjects

One subject for each component entry point that the reference apps run (selected with the coverage data).

| Class                        | Subjects                                                   |
|------------------------------|------------------------------------------------------------|
| `Container\ContainerBench`   | `benchGet`                                                 |
| `Db\PdoBench`                | `benchFetchAll`, `benchFetchOneBound`                      |
| `Di\DiBench`                 | `benchFactoryDefault`, `benchGetNew`, `benchGetShared`     |
| `Events\ManagerBench`        | `benchFire`, `benchFireNoListener`                         |
| `Filter\FilterBench`         | `benchSanitize`                                            |
| `Html\EscaperBench`          | `benchHtml`                                                |
| `Http\ResponseBench`         | `benchSend`, `benchSetJsonContent`                         |
| `Mvc\DispatcherBench`        | `benchDispatch`                                            |
| `Mvc\ModelBench`             | `benchFind`, `benchFindFirst`, `benchSave`, `benchToArray` |
| `Mvc\QueryBench`             | `benchParseCold`, `benchParseWarm`                         |
| `Mvc\RouterBench`            | `benchDefineAndHandle`, `benchHandle`                      |
| `Mvc\ViewBench`              | `benchPartial`, `benchRender`                              |
| `Mvc\VoltBench`              | `benchCompileString`                                       |
| `Support\CollectionBench`    | `benchGet`                                                 |
| `Support\JsonBench`          | `benchEncode`                                              |

- The subjects use the fixtures of the reference apps (`Apps\Mvc\Fixture`, `Apps\Rest\Fixture`).
- `benchParseCold` uses a new PHQL string for each call, so both PHQL caches miss. The caches grow during
  the run.
- For heavy subjects (Router, View, Model, Query, Db, `benchFactoryDefault`), use a smaller k (for example
  200) with `bin/instr`.

## Reference apps

`Apps/` has four small apps. Each subject call is one request: a new container and a new application,
`handle()`, `send()` into an output buffer, and a check of the body.

| App           | Subjects                                                        |
|---------------|-----------------------------------------------------------------|
| Micro         | `Apps\Micro\MicroBench::benchHello`                             |
| ADR           | `Apps\Adr\AdrBench::benchHello`                                 |
| MVC + Volt    | `Apps\Mvc\MvcBench::benchPage`                                  |
| REST + SQLite | `Apps\Rest\RestBench::benchList`, `benchShow`, `benchCreate`    |

- The fixtures (SQLite database, compiled Volt files, model metadata) are in `.local/bench/fixtures/`.
  `setUp` creates them if they are missing. The measured runs use these cache files, as in production.
- `cold_ir` is the first request in a new process. It includes one-time process costs that php-fpm pays once
  for each worker (PHP script compile, regex compile). `warm_ir` is a request in a process that already ran
  requests: all caches are full, also request-scoped caches (for example the PHQL cache) that php-fpm empties
  after each request. A php-fpm request is between the two.
- A request is much heavier than a micro subject. Use a smaller k:

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/instr <build> 'Phalcon\Tests\Benchmarks\Apps\Mvc\MvcBench' benchPage 200
```

- PHPBench for the apps only:

```bash
docker exec -e PHP_BENCH_BUILD=<build> cphalcon-bench-8.4 \
    vendor/bin/phpbench run --config=resources/phpbench.json --report=aggregate tests/benchmarks/Apps
```

## Coverage (which code runs)

`bin/coverage` shows which functions run in one call of a subject, and their cost. It runs the subject under
callgrind with 0, 1 and 1+k calls (k is 20 if not given):

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/coverage <build> 'Phalcon\Tests\Benchmarks\Apps\Mvc\MvcBench' benchPage
```

The report is in `.local/bench/out/coverage/<build>/`. For the cold and the warm call it shows the calls, the
self Ir and the inclusive Ir: by component, the top Phalcon methods (`Class::method`), the top `zephir_*`
runtime helpers and the top other functions.

Limits:

- The compiler folds identical small methods. The other copies jump to the kept copy, so their cost shows
  under the name of the kept copy (for example `Mvc\View::phpFileExists` shows as
  `Assets\Asset::phpFileExists`).
- The `php` binary has no symbols. Its functions (for example the script compiler) show as addresses.
- Recursive functions count some inclusive cost twice.

## Memory

Allocations (valgrind DHAT, with `USE_ZEND_ALLOC=0`, so each `emalloc` is one allocation):

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/allocs <build> 'Phalcon\Tests\Benchmarks\Apps\Micro\MicroBench' benchHello
```

It prints the allocations and the bytes of the cold call and of one warm call (k is 100 if not given).
The counts are the same in each run.

Peak, retained and leaked memory, and reference cycles (no valgrind, fast):

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/memory <build> 'Phalcon\Tests\Benchmarks\Apps\Mvc\MvcBench' benchPage
```

- `peak_bytes`: the peak of one call, above the memory before the call.
- `retained_bytes_per_call`: the memory that stays after k calls, for each call, before a garbage collection.
- `leaked_bytes_per_call`: the same after a garbage collection (memory that is still referenced).
- `cycles_per_call`: the reference cycles that the garbage collector collected, for each call.

The results are in `.local/bench/out/allocs/<build>/` and `.local/bench/out/memory/<build>/`.

## Full run and A/B comparison

`bin/run-all` runs `bin/instr`, `bin/memory` and `bin/allocs` for all subjects and writes one row for each
subject into `.local/bench/results/<build>/<label>/metrics.tsv`. A full run takes about 20 minutes. A filter
(a regular expression on `<class>::<method>`) runs a part; a new run of a subject replaces its row.

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/run-all <build> <label>
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/run-all <build> <label> 'Benchmarks.Apps.'
```

`bin/run-time` runs PHPBench one time for all subjects and writes `time.tsv` into the same folder. Stop the
other containers first, and pin to one CPU (here CPU 5): pinning halves the noise.

```bash
docker exec cphalcon-bench-8.4 tests/benchmarks/bin/run-time <build> <label> 5
```

`bin/compare.php` compares two results folders (A = before, B = after). Each difference is better, worse or
noise:

```bash
docker exec cphalcon-bench-8.4 php tests/benchmarks/bin/compare.php \
    /srv/.local/bench/results/<build-a>/<label-a> /srv/.local/bench/results/<build-b>/<label-b>
```

A difference counts only if it is at or above both thresholds of its metric (3 times the largest difference
of an A/A run, with relative floors): `warm_ir` 0.5% and 70 Ir, `cold_ir` 1% and 7,500 Ir, warm allocations 1,
cold allocations 6, warm bytes 1% and 3 bytes, peak, retained and leaked 1% and 64 bytes, cycles 1, wall time 5%.
Two runs of the same build give only noise.

The A/B loop for a change:

1. Store the build before the change and run `run-all` (and `run-time`) with a label.
2. Make the change, `bin/build-so`, `bin/store-build <label>`.
3. Run `run-all` (and `run-time`) on the new build.
4. `compare.php` before and after. Keep the change if it is better and nothing is worse.

## Write a benchmark

- One class for each area, in `tests/benchmarks/<Component>/<Name>Bench.php`, namespace
  `Phalcon\Tests\Benchmarks\<Component>`.
- Subject methods start with `bench`. Put the setup in a method named in `#[BeforeMethods(...)]`.
- Each subject checks its result and throws `RuntimeException` if it is wrong.
- `#[ParamProviders]` is not supported by `bin/instr`.
- `#[Revs]` sets the PHPBench revs and the k of `bin/instr` in `bin/run-all`. The default is 1000. Use
  `#[Revs(200)]` (or 100 for a full request) for heavy subjects.
- A subject must not print output (PHPBench reads the output of its child process). Put `send()` between
  `ob_start()` and `ob_get_clean()`.
- An app subject calls `Di::reset()` before `new FactoryDefault()`. php-fpm clears the default container at
  the end of each request. Without the reset, the models use the container of the first request.
- Micro and the container bind closures to an object. Do not use `static` closures for route handlers or
  services.
- The code style is the same as for the tests (phpcs, php-cs-fixer).

## Scripts

| Script             | Container | Purpose                                                               |
|--------------------|-----------|-----------------------------------------------------------------------|
| `bin/allocs`       | bench     | Allocations of one subject (DHAT)                                     |
| `bin/build-so`     | dev       | Compiles the extension with the release flags plus `-g`               |
| `bin/compare.php`  | bench     | Compares two results folders (better, worse, noise)                   |
| `bin/coverage`     | bench     | Functions that run in one call of a subject, with their cost          |
| `bin/coverage.php` | bench     | Reads the callgrind files and writes the coverage report              |
| `bin/store-build`  | dev       | Stores the build in `.local/bench/so/` with a manifest                |
| `bin/php-bench`    | bench     | Runs PHP under fixed conditions (the only way to run PHP here)        |
| `bin/phpbench-php` | bench     | PHPBench runs this as its PHP binary; calls `php-bench`               |
| `bin/run-all`      | bench     | instr, memory and allocs for all subjects into a results folder       |
| `bin/run-time`     | bench     | PHPBench wall time for all subjects into a results folder             |
| `bin/instr`        | bench     | Cold and warm instruction counts of one subject                       |
| `bin/lib/subject.php` | bench  | Creates a benchmark class and runs its setup (used by the drivers)    |
| `bin/memory`       | bench     | Peak, retained and leaked memory, reference cycles of one subject     |
| `bin/memory.php`   | bench     | The memory driver (`bin/memory` runs it)                              |
| `bin/subject.php`  | bench     | Runs one subject N times (`bin/instr` uses it)                        |
| `bin/subjects.php` | bench     | Lists all subjects and their revs (`bin/run-all` uses it)             |
