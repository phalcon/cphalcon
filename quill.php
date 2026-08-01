<?php

/**
 * Scribe configuration - https://github.com/phalcon/scribe
 *
 * Replaces bin/generate-api-docs.php. `source` and `output` are relative to
 * this file; `repository`, `branch` and `prefix` build the "Source on GitHub"
 * link on every class.
 */

declare(strict_types=1);

return [
    'language'   => 'zephir',
    'source'     => 'phalcon',
    'output'     => 'nikos/api',
    'repository' => 'phalcon/cphalcon',
    'branch'     => '5.0.x',
    'prefix'     => 'phalcon',
    'extension'  => 'zep',
];
