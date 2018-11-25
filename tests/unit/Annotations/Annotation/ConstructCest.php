<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Annotation;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsAnnotationConstruct(UnitTester $I)
    {
        $I->wantToTest("Annotations\Annotation - __construct()");
        $I->skipTest("Need implementation");
    }
}
