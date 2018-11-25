<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Collection;

use UnitTester;

class GetAnnotationsCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: getAnnotations()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsCollectionGetAnnotations(UnitTester $I)
    {
        $I->wantToTest("Annotations\Collection - getAnnotations()");
        $I->skipTest("Need implementation");
    }
}
