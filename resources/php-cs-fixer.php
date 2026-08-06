<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

/**
 * Ordering rules:
 * - use statements: alphabetical
 * - class members: by visibility (public -> protected -> private), then
 *   alphabetical within each group
 *
 * Run from the project root:
 *   composer cs-fixer       (dry-run, shows diff)
 *   composer cs-fixer-fix   (applies the changes)
 */

use PhpCsFixer\Config;
use PhpCsFixer\Finder;
use PhpCsFixer\Runner\Parallel\ParallelConfigFactory;

$root = dirname(__DIR__);

$finder = Finder::create()
    ->in(
        [
            $root . '/tests/unit',
            $root . '/tests/database',
        ]
    );

return (new Config())
    ->setParallelConfig(ParallelConfigFactory::detect())
    // declare_strict_types is a risky rule.
    ->setRiskyAllowed(true)
    ->setUsingCache(true)
    ->setCacheFile($root . '/tests/_output/.php-cs-fixer.cache')
    ->setRules(
        [
            'declare_strict_types'   => true,
            'no_unused_imports'      => true,
            'ordered_imports'        => [
                'sort_algorithm' => 'alpha',
                'imports_order'  => ['class', 'function', 'const'],
            ],
            'ordered_class_elements' => [
                'sort_algorithm' => 'alpha',
                'order'          => [
                    'use_trait',
                    'case',
                    'constant_public',
                    'constant_protected',
                    'constant_private',
                    'property_public_static',
                    'property_protected_static',
                    'property_private_static',
                    'property_public',
                    'property_protected',
                    'property_private',
                    'construct',
                    'destruct',
                    'magic',
                    'phpunit',
                    'method_public_static',
                    'method_protected_static',
                    'method_private_static',
                    'method_public',
                    'method_protected',
                    'method_private',
                ],
            ],
            /**
             * Both sorters default `null_adjustment` to 'always_first', which
             * would rewrite every `string|null` to `null|string`. Phalcon puts
             * null last, and so does the model quill builds from both this and
             * the Zephir source, so last it stays.
             */
            'ordered_types'          => [
                'sort_algorithm'  => 'alpha',
                'null_adjustment' => 'always_last',
            ],
            'phpdoc_types_order'     => [
                'sort_algorithm'  => 'alpha',
                'null_adjustment' => 'always_last',
            ],
            'types_spaces'           => [
                'space' => 'single',
            ],
        ]
    )
    ->setFinder($finder);