<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\AnnotationsFactory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\AnnotationsFactory;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Annotations\AdapterFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     */
    public function annotationsAdapterFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Annotations\AdapterFactory - newInstance()');

        $factory = new AnnotationsFactory();
        $name    = 'apcu';

        $image = $factory->newInstance($name);

        $I->assertInstanceOf(
            Apcu::class,
            $image
        );
    }
}
