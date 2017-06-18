<?php

namespace Phalcon\Test\Unit\Translate\Interpolator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Interpolator\IndexedArray;

/**
 * \Phalcon\Test\Unit\Translate\Interpolator\IndexedArrayTest
 * Tests the \Phalcon\Translate\Interpolator\IndexedArray component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Translate\Interpolator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class IndexedArrayTest extends UnitTest
{
    private $config = null;

    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        $this->config = [
            'ru' => [
                'Hello!'          => 'Привет!',
                'Hello %s %s %s!' => 'Привет, %s %s %s!',
            ],
        ];
    }

    public function testIndexedArrayInterpolator()
    {
        $this->specify(
            "Test Translator with IndexedArray interpolator fails",
            function () {
                $language   = $this->config['ru'];
                $params     = ['content' => $language, 'interpolator' => new IndexedArray()];
                $translator = new NativeArray($params);

                $expected = 'Привет, John D. Doe!';
                $actual = $translator->_(
                    'Hello %s %s %s!',
                    [
                        'John',
                        'D.',
                        'Doe',
                    ]
                );
                expect($actual)->equals($expected);
            }
        );
    }

    public function testReplacePlaceholders()
    {
        $this->specify(
            "replacePlaceholders returns incorrect result",
            function () {
                $interpolator = new IndexedArray();

                $expected = 'Hello, John D. Doe!';

                $stringFrom = 'Hello, %s %s %s!';
                $actual = $interpolator->replacePlaceholders($stringFrom, ['John', 'D.', 'Doe']);

                expect($expected)->equals($actual);
            }
        );
    }
}
