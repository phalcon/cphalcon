<?php

namespace Phalcon\Test\Integration\Mvc\Collection;

use Helper\CollectionTrait;
use IntegrationTester;
use Phalcon\Test\Collections\Subs;

/**
 * \Phalcon\Test\Integration\Mvc\Collection\BehaviorCest
 * Tests the Phalcon\Mvc\Collection component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Integration\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BehaviorCest
{
    use CollectionTrait;

    public function behaviors(IntegrationTester $I)
    {
        $this->setupMongo($I);

        $I->wantToTest('using behaviors with collections');

        // Timestampable
        $subscriber = new Subs();
        $subscriber->email = 'some@some.com';
        $subscriber->status = 'I';
        $I->assertTrue($subscriber->save());
        $I->assertEquals(1, preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}/', $subscriber->created_at));

        // Soft delete
        $total = Subs::count();
        $subscriber = Subs::findFirst();
        $I->assertTrue($subscriber->delete());
        $I->assertEquals($subscriber->status, 'D');
        $I->assertEquals(Subs::count(), $total);
    }
}
