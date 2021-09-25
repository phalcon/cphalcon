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

namespace Phalcon\Tests\Unit\Translate\TranslateFactory;

use Phalcon\Tests\Fixtures\Traits\TranslateCsvTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;
use Phalcon\Translate\TranslateFactory;
use UnitTester;

class NewInstanceCest
{
    use TranslateCsvTrait;

    /**
     * Tests Phalcon\Translate\TranslateFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function translateTranslateFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Translate\TranslateFactory - newInstance()');

        $interpolator = new InterpolatorFactory();
        $factory      = new TranslateFactory($interpolator);
        $language     = $this->getCsvConfig()['ru'];
        $adapter      = $factory->newInstance('csv', $language);

        $I->assertInstanceOf(Csv::class, $adapter);
        $I->assertInstanceOf(AdapterInterface::class, $adapter);
    }
}
