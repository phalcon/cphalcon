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

namespace Phalcon\Test\Integration\Session\Bag;

use ArrayAccess;
use Countable;
use IntegrationTester;
use IteratorAggregate;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Session\Bag;
use Phalcon\Session\BagInterface;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

/**
 * Class InitializeCest
 */
class InitializeCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: initialize()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagInitialize(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - initialize()");
        $session = new Bag("SetTest");

        $I->assertInstanceOf(InjectionAwareInterface::class, $session);
        $I->assertInstanceOf(BagInterface::class, $session);
        $I->assertInstanceOf(IteratorAggregate::class, $session);
        $I->assertInstanceOf(ArrayAccess::class, $session);
        $I->assertInstanceOf(Countable::class, $session);
    }
}
