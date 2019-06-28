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
    'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Image\\Adapter',
    'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
    'line' => 13,
    'char' => 9,
  ),
  2 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
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
          'name' => 'background',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'color',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 15,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'opacity',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 15,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 15,
              'char' => 63,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 15,
          'last-line' => 17,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'blur',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'radius',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 17,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 17,
          'last-line' => 19,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'crop',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'width',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 19,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'height',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 19,
              'char' => 47,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetX',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 19,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 19,
              'char' => 67,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetY',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 19,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 19,
              'char' => 87,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 19,
          'last-line' => 21,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'flip',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'direction',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 21,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 21,
          'last-line' => 23,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'mask',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'watermark',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 23,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 23,
              'char' => 54,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 23,
          'last-line' => 25,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'pixelate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'amount',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 25,
              'char' => 40,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 25,
          'last-line' => 27,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reflection',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'height',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 27,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'opacity',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 27,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 27,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'fadeIn',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 27,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 27,
              'char' => 82,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 27,
          'last-line' => 29,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'ext',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 29,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 29,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'quality',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 29,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 29,
              'char' => 64,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 29,
          'last-line' => 31,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'resize',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'width',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 31,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 31,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'height',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 31,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 31,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'master',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'Image',
                  'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                  'line' => 31,
                  'char' => 89,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'AUTO',
                  'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                  'line' => 31,
                  'char' => 89,
                ),
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 31,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 31,
              'char' => 89,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 31,
          'last-line' => 33,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rotate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'degrees',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 33,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 33,
          'last-line' => 35,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'save',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 35,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 35,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'quality',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 35,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 35,
              'char' => 63,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 35,
          'last-line' => 37,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'sharpen',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'amount',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 37,
              'char' => 39,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 37,
          'last-line' => 39,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'text',
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
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetX',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 54,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetY',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 71,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'opacity',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 90,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'color',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '000000',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 113,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 113,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'size',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '12',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 128,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 128,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'fontfile',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 39,
                'char' => 152,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 39,
              'char' => 152,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 39,
          'last-line' => 41,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'watermark',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'watermark',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 41,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 41,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetX',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 41,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 41,
              'char' => 76,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'offsetY',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 41,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 41,
              'char' => 93,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'opacity',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '100',
                'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
                'line' => 41,
                'char' => 112,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
              'line' => 41,
              'char' => 112,
            ),
          ),
          'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
          'line' => 41,
          'last-line' => 42,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
      'line' => 42,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Image/Adapter/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);