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

namespace Phalcon\Test\Unit\Annotations\Annotation;

use UnitTester;

/**
 * Class GetArgumentsCest
 */
class GetArgumentsCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: getArguments()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsAnnotationGetArguments(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getArguments()');
        $I->skipTest('Need implementation');
    }
}
