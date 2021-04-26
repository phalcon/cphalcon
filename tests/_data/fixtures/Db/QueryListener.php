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

namespace Phalcon\Test\Fixtures\Db;

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Di\Injectable;
use Phalcon\Events\Event;
use Phalcon\Logger;

/**
 * Class QueryListener
 *
 * @package Phalcon\Test\Fixtures\Db
 *
 * @property Logger $logger
 */
class QueryListener extends Injectable
{
    /**
     * @param Event            $event
     * @param AdapterInterface $connection
     */
    public function beforeQuery(Event $event, AdapterInterface $connection)
    {
        $this->logger->info(
            sprintf(
                '%s - [%s]',
                $connection->getSQLStatement(),
                json_encode($connection->getSQLVariables())
            )
        );
    }
}
