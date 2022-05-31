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

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class RegenerateIdCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: regenerateId()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerRegenerateId(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - regenerateId()');

        $manager = new Manager();

        $files = $this->newService('sessionStream');

        $manager->setAdapter($files);
        $manager->start();

        $current = $manager->getId();

        $manager->regenerateId(true);

        $I->assertNotEquals(
            $current,
            $manager->getId()
        );

        $manager->destroy();
    }
}
