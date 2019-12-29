<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Annotations\Annotation;

use UnitTester;

class GetNamedArgumentCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: getNamedArgument()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAnnotationGetNamedArgument(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getNamedArgument()');

        $I->skipTest('Need implementation');
    }
}
