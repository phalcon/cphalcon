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

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: __construct()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAnnotationConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - __construct()');

        $annotation = new Annotation([
            'name' => 'NovAnnotation',
        ]);

        $I->assertInstanceOf(
            Annotation::class,
            $annotation
        );
    }
}
