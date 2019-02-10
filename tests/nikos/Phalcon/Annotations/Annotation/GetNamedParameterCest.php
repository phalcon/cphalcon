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
 * Class GetNamedParameterCest
 */
class GetNamedParameterCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: getNamedParameter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function annotationsAnnotationGetNamedParameter(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getNamedParameter()');
        $I->skipTest('Need implementation');
    }
}
