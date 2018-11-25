<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Reflection;

use UnitTester;

class GetClassAnnotationsCest
{
    /**
     * Tests Phalcon\Annotations\Reflection :: getClassAnnotations()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsReflectionGetClassAnnotations(UnitTester $I)
    {
        $I->wantToTest("Annotations\Reflection - getClassAnnotations()");
        $I->skipTest("Need implementation");
    }
}
