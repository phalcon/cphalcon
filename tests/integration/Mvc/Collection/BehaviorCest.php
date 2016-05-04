<?php

namespace Phalcon\Test\Integration\Mvc;

use Helper\Collection;
use IntegrationTester;
use Phalcon\Test\Collections\Subs;

class BehaviorCest
{
    use Collection;

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
