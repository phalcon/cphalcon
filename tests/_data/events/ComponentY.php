<?php

use Phalcon\Events\Manager;

/**
 * ComponentY
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ComponentY
{
    /**
     * @var Manager
     */
    protected $eventsManager;

    public function setEventsManager(Manager $eventsManager)
    {
        $this->eventsManager = $eventsManager;
    }

    /**
     * @return Manager
     */
    public function getEventsManager()
    {
        return $this->eventsManager;
    }

    public function leAction()
    {
        $this->eventsManager->fire('another:beforeAction', $this);
        $this->eventsManager->fire('another:afterAction', $this);
    }
}
