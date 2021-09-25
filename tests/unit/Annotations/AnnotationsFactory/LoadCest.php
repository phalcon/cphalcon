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

namespace Phalcon\Tests\Unit\Annotations\AnnotationsFactory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\AnnotationsFactory;
use Phalcon\Tests\Fixtures\Traits\FactoryTrait;
use UnitTester;

class LoadCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Annotations\AnnotationsFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function imageAnnotationsFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Annotations\AnnotationsFactory - load()');

        $options = $this->config->annotations;
        $this->runTests($I, $options);
    }

    /**
     * Tests Phalcon\Annotations\AnnotationsFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function imageAnnotationsFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Annotations\AnnotationsFactory - load()');

        $options = $this->arrayConfig['annotations'];
        $this->runTests($I, $options);
    }

    private function runTests(UnitTester $I, $options)
    {
        $factory = new AnnotationsFactory();

        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            Apcu::class,
            $adapter
        );
    }
}
