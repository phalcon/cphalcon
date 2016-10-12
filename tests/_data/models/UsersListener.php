<?php


namespace Phalcon\Test\Models;

use Phalcon\Events\Event;

class UsersListener extends \Phalcon\Di\Injectable
{
    public function beforeSave(Event $event, UsersWithListener $usersWithListener)
    {
        $usersWithListener->name = 'test user after event';
        return true;
    }

    public function beforeDelete(Event $event, UsersWithListener $usersWithListener)
    {
    }

}
