<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * Quill configuration - https://github.com/phalcon/quill
 *
 * Replaces bin/generate-api-docs.php. `source`, `output` and `assets` are
 * relative to this file; `repository`, `branch` and `prefix` build the
 * "Source on GitHub" link on every class.
 *
 * `output` and `assets` mirror the documentation site's own layout, so
 * `cp -r nikos/docs/* <documentation>/docs/` lands the pages and the
 * stylesheet where each belongs.
 */

declare(strict_types=1);

return [
    'language'   => 'zephir',
    'source'     => 'phalcon',
    'output'     => 'nikos/docs/api',
    'assets'     => 'nikos/docs/assets/css',
    'repository' => 'phalcon/cphalcon',
    'branch'     => '5.0.x',
    'prefix'     => 'phalcon',
    'extension'  => 'zep',
    'namespace'  => 'Phalcon',
];
