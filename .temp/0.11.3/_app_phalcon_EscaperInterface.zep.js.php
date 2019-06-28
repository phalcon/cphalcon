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
    'file' => '/app/phalcon/EscaperInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/EscaperInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Escaper
 *',
    'file' => '/app/phalcon/EscaperInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'EscaperInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeCss',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'css',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 22,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 22,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 22,
            'char' => 52,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 22,
          'last-line' => 26,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeHtml',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 27,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Escapes a HTML string
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 27,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 27,
            'char' => 54,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 27,
          'last-line' => 31,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeHtmlAttr',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 32,
              'char' => 47,
            ),
          ),
          'docblock' => '**
     * Escapes a HTML attribute string
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 32,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 32,
            'char' => 58,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 32,
          'last-line' => 37,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeJs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'js',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 38,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Escape Javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 38,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 38,
            'char' => 50,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'escapeUrl',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 43,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Escapes a URL. Internally uses rawurlencode
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 43,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 43,
            'char' => 52,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEncoding',
          'docblock' => '**
     * Returns the internal encoding used by the escaper
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
                'file' => '/app/phalcon/EscaperInterface.zep',
                'line' => 48,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 48,
            'char' => 44,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEncoding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'encoding',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 53,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Sets the encoding to be used by the escaper
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 53,
            'char' => 57,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHtmlQuoteType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'quoteType',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/EscaperInterface.zep',
              'line' => 58,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets the HTML quoting type for htmlspecialchars
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/EscaperInterface.zep',
            'line' => 58,
            'char' => 60,
          ),
          'file' => '/app/phalcon/EscaperInterface.zep',
          'line' => 58,
          'last-line' => 59,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/EscaperInterface.zep',
      'line' => 59,
      'char' => 1,
    ),
    'file' => '/app/phalcon/EscaperInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);