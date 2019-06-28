<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Query',
    'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
    'line' => 31,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Query\\Lang
 *
 * PHQL is implemented as a parser (written in C) that translates syntax in
 * that of the target RDBMS. It allows Phalcon to offer a unified SQL language to
 * the developer, while internally doing all the work of translating PHQL
 * instructions to the most optimal SQL instructions depending on the
 * RDBMS type associated with a model.
 *
 * To achieve the highest performance possible, we wrote a parser that uses
 * the same technology as SQLite. This technology provides a small in-memory
 * parser with a very low memory footprint that is also thread-safe.
 *
 * ```php
 * $intermediate = Phalcon\\Mvc\\Model\\Query\\Lang::parsePHQL(
 *     "SELECT r.* FROM Robots r LIMIT 10"
 * );
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
    'line' => 32,
    'char' => 8,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Lang',
    'abstract' => 1,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'parsePHQL',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'phql',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
              'line' => 37,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'phql_parse_phql',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'phql',
                      'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
                      'line' => 39,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
                    'line' => 39,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
                'line' => 39,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Parses a PHQL statement returning an intermediate representation (IR)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
                'line' => 38,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
          'line' => 37,
          'last-line' => 41,
          'char' => 26,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
      'line' => 32,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Lang.zep',
    'line' => 32,
    'char' => 14,
  ),
);