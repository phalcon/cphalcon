<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Phalcon\Di\Injectable as AbstractInjectable;

/**
 * InjectableComponent class
 */
class InjectableComponent extends AbstractInjectable
{
    public $response;

    public $other;

    public function __construct($response = null)
    {
        $this->response = $response;
    }

    public function setResponse($response)
    {
        $this->response = $response;
    }

    public function getResponse()
    {
        return $this->response;
    }
}
