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

namespace Phalcon\Tests\Integration\Session\Manager;

use Codeception\Stub;
use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class StartCest
 *
 * @package Phalcon\Tests\Integration\Session\Manager
 */
class StartCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: start() - headers sent
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerStartHeadersSent(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - start() - headers sent');
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $mock = Stub::make(
            $manager,
            [
                'phpHeadersSent' => true,
            ]
        );

        $actual = $mock->start();
        $I->assertFalse($actual);

        $manager->destroy();
    }
}
