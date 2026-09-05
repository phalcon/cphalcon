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
            /**
             * Aligns the `=` of consecutive assignments and the `=>` of
             * consecutive array elements. The compound assignments join the
             * same run, so a `.=` between two `=` lines keeps the column. A
             * run ends at the first line without one of these operators, so
             * unrelated blocks stay independent. Every other operator keeps
             * the single space PSR-12 asks for.
             */
            'binary_operator_spaces'                        => [
                'default'   => 'single_space',
                'operators' => [
                    '='   => 'align',
                    '+='  => 'align',
                    '-='  => 'align',
                    '*='  => 'align',
                    '/='  => 'align',
                    '.='  => 'align',
                    '%='  => 'align',
                    '**=' => 'align',
                    '??=' => 'align',
                    '=>'  => 'align',
                ],
            ],
            'declare_strict_types'                          => true,
            'no_empty_phpdoc'                               => true,
            /**
             * Removes `@param`, `@return` and `@var` tags that only repeat the
             * native type. A tag is removed only when it has no description and
             * its type is the same as the signature, so shapes such as
             * `array<string, mixed>` stay. `allow_mixed` keeps `@param mixed`.
             */
            'no_superfluous_phpdoc_tags'                    => [
                'allow_mixed'         => true,
                'allow_unused_params' => false,
                'remove_inheritdoc'   => false,
            ],
            'no_unused_imports'                             => true,
            'ordered_imports'                               => [
                'sort_algorithm' => 'alpha',
                'imports_order'  => ['class', 'function', 'const'],
            ],
            'ordered_class_elements'                        => [
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
            'ordered_types'                                 => [
                'sort_algorithm'  => 'alpha',
                'null_adjustment' => 'always_last',
            ],
            'phpdoc_align'                                  => [
                'align' => 'vertical',
                'tags'  => [
                    'method',
                    'param',
                    'property',
                    'return',
                    'throws',
                    'type',
                    'var',
                ],
            ],
            'phpdoc_trim'                                   => true,
            'phpdoc_trim_consecutive_blank_line_separation' => true,
            'phpdoc_types_order'                            => [
                'sort_algorithm'  => 'alpha',
                'null_adjustment' => 'always_last',
            ],
            'types_spaces'                                  => [
                'space' => 'single',
            ],
        ]
    )
    ->setFinder($finder);