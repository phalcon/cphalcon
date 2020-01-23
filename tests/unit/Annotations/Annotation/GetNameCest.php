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

use Phalcon\Annotations\Annotation;
use UnitTester;

class GetNameCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: getName()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAnnotationGetName(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - getName()');

        $sName = 'NovAnnotation';

        $oAnnotation = new Annotation([
            'name' => 'NovAnnotation'
        ]);

        $I->assertEquals($oAnnotation->getName(), $sName);
    }
}
