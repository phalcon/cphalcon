<?php
declare(strict_types=1);

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

/**
 * Class GetMethodsAnnotationsCest
 */
class GetMethodsAnnotationsCest
{
    /**
     * Tests Phalcon\Annotations\Reflection :: getMethodsAnnotations()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsReflectionGetMethodsAnnotations(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - getMethodsAnnotations()');
        $I->skipTest('Need implementation');
    }
}
