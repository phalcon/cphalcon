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

namespace Phalcon\Test\Unit\Annotations\AnnotationsFactory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\AnnotationsFactory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function imageAnnotationsFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Annotations\AnnotationsFactory - load()');

        $options = $this->config->annotations;
        $factory = new AnnotationsFactory();

        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            Apcu::class,
            $adapter
        );
    }

    /**
     * Tests Phalcon\Annotations\AnnotationsFactory :: load()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function imageAnnotationsFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Annotations\AnnotationsFactory - load()');

        $options = $this->arrayConfig['annotations'];
        $factory = new AnnotationsFactory();

        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            Apcu::class,
            $adapter
        );
    }
}
