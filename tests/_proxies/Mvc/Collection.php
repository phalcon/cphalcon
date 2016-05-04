<?php

namespace Phalcon\Test\Proxy\Mvc;

use Phalcon\Mvc\Collection as PhCollection;
use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Collection\ManagerInterface;
use Phalcon\DiInterface;

/**
 * \Phalcon\Test\Proxy\Mvc\Collection
 * Url proxy class for \Phalcon\Mvc\Collection
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Collection extends PhCollection
{
    public function setId($id)
    {
        parent::setId($id);
    }

    public function getId()
    {
        return parent::getId();
    }

    public function setDI(DiInterface $dependencyInjector)
    {
        parent::setDI($dependencyInjector);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    protected function setEventsManager(ManagerInterface $eventsManager)
    {
        parent::setEventsManager($eventsManager);
    }

    protected function getEventsManager()
    {
        return parent::getEventsManager();
    }

    public function getCollectionManager()
    {
        return parent::getCollectionManager();
    }

    public function getReservedAttributes()
    {
        return parent::getReservedAttributes();
    }

    public function getSource()
    {
        return parent::getSource();
    }

    public function setConnectionService($connectionService)
    {
        return parent::setConnectionService($connectionService);
    }

    public function getConnectionService()
    {
        return parent::getConnectionService();
    }

    public function getConnection()
    {
        return parent::getConnection();
    }

    public function readAttribute($attribute)
    {
        return parent::readAttribute($attribute);
    }

    public function writeAttribute($attribute, $value)
    {
        return parent::writeAttribute($attribute, $value);
    }

    public static function cloneResult(CollectionInterface $collection, array $document)
    {
        return parent::cloneResult($collection, $document);
    }

    public function validationHasFailed()
    {
        return parent::validationHasFailed();
    }

    public function fireEvent($eventName)
    {
        return parent::fireEvent($eventName);
    }

    public function fireEventCancel($eventName)
    {
        return parent::fireEventCancel($eventName);
    }

    public function getMessages()
    {
        return parent::getMessages();
    }

    public function appendMessage(MessageInterface $message)
    {
        parent::appendMessage($message);
    }

    public function save()
    {
        return parent::save();
    }

    public function create()
    {
        return parent::create();
    }

    public function createIfNotExist(array $criteria)
    {
        return parent::createIfNotExist($criteria);
    }

    public function update()
    {
        return parent::update();
    }

    public static function findById($id)
    {
        return parent::findById($id);
    }

    public static function findFirst(array $parameters = null)
    {
        return parent::findFirst($parameters);
    }

    public static function find(array $parameters = null)
    {
        return parent::find($parameters);
    }

    public static function count(array $parameters = null)
    {
        return parent::count($parameters);
    }

    public static function aggregate(array $parameters = null)
    {
        return parent::aggregate($parameters);
    }

    public static function summatory($field, $conditions = null, $finalize = null)
    {
        return parent::summatory($field, $conditions, $finalize);
    }

    public function delete()
    {
        return parent::delete();
    }

    public function skipOperation($skip)
    {
        parent::skipOperation($skip);
    }

    public function toArray()
    {
        return parent::toArray();
    }

    public function serialize()
    {
        return parent::serialize();
    }

    public function unserialize($data)
    {
        parent::unserialize($data);
    }
}
