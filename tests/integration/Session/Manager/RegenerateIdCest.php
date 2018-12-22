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

namespace Phalcon\Test\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

/**
 * Class RegenerateIdCest
 */
class RegenerateIdCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * Tests Phalcon\Session\Manager :: regenerateId()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionManagerRegenerateId(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - regenerateId()');
        $manager = new Manager();
        $files   = $this->getSessionFiles();
        $manager->setHandler($files);
        $manager->start();

        $current = $manager->getId();
        $manager->regenerateId(true);
        $actual = $manager->getId();
        $I->assertNotEquals($current, $actual);
        $manager->destroy();
    }
}
