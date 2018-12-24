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
 * Class GetExpressionCest
 */
class GetExpressionCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: getExpression()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsAnnotationGetExpression(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getExpression()');
        $I->skipTest('Need implementation');
    }
}
