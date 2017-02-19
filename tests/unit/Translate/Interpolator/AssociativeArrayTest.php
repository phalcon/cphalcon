<?php

namespace Phalcon\Test\Unit\Translate\Interpolator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Translate\Interpolator\AssociativeArray;

/**
 * \Phalcon\Test\Unit\Translate\Interpolator\AssociativeArrayTest
 * Tests the \Phalcon\Translate\Interpolator\AssociativeArray component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Translate\Interpolator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AssociativeArrayTest extends UnitTest
{
    public function testIndexedArrayInterpolator()
    {
        $this->specify(
            "replacePlaceholders returns incorrect result",
            function () {
                $interpolator = new AssociativeArray();

                $expected = 'Hello, John D. Doe!';

                $stringFrom = 'Hello, %fname% %mname% %lname%!';
                $actual = $interpolator->replacePlaceholders(
                    $stringFrom,
                    [
                        'fname' => 'John',
                        'lname' => 'Doe',
                        'mname' => 'D.'
                    ]
                );

                expect($expected)->equals($actual);
            }
        );
    }
}
