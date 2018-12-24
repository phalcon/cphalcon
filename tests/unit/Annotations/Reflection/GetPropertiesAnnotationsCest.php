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
 * Class GetPropertiesAnnotationsCest
 */
class GetPropertiesAnnotationsCest
{
    /**
     * Tests Phalcon\Annotations\Reflection :: getPropertiesAnnotations()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsReflectionGetPropertiesAnnotations(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - getPropertiesAnnotations()');
        $I->skipTest('Need implementation');
    }
}
