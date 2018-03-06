<?php

/**
 * Fixture for View engines test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use Phalcon\Test\Objectsets\Mvc\View\IteratorObject;

return [
    [
        [
            'engines' => [
                '.volt' => 'Phalcon\Mvc\View\Engine\Volt'
            ],
            'setVar' => [
                ['arr', [1, 2, 3, 4]],
                ['obj', new IteratorObject([1, 2, 3, 4])],
                ['str', 'hello'],
                ['no_str', 1234],
            ],
            'render' => ['test11', 'index'],
            'removeFiles' => [],
        ],
        'Length Array: 4Length Object: 4Length String: 5Length No String: 4Slice Array: 1,2,3,4Slice Array: 2,3Slice Array: 1,2,3Slice Object: 2,3,4Slice Object: 2,3Slice Object: 1,2Slice String: helSlice String: elSlice String: lloSlice No String: 123Slice No String: 23Slice No String: 34',
    ],
];
