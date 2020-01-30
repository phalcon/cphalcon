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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model;

/**
 * Class SetupCest
 */
class SetupCest
{
    public function testSetupCacheLevel(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - setup() cache level');
        $this->setAndCheckValue($I, 'cacheLevel', -1);
        $this->setAndCheckValue($I, 'cacheLevel', 1);
    }

    public function testSetupEvents(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - setup() events');
        $this->setAndCheckValue($I, 'events', false);
        $this->setAndCheckValue($I, 'events', true);
    }

    public function testPrefetchRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - setup() prefetch records');
        $this->setAndCheckValue($I, 'prefetchRecords', 20);
        $this->setAndCheckValue($I, 'prefetchRecords', 0);
    }

    protected function setAndCheckValue(IntegrationTester $I, $key, $value)
    {
        $currentSetup = Model::getModelSetup();
        $I->assertIsArray($currentSetup);
        Model::setup([
            $key => $value,
        ]);
        $I->arrayHasKey($key, Model::getModelSetup());
        $I->assertEquals($value, Model::getModelSetup()[$key]);
        Model::setup($currentSetup);
    }
}
