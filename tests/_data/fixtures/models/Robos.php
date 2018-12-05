<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * @author  David Napierata
 */
class Robos extends Model
{
    public function getSource(): string
    {
        return 'robots';
    }

    public function initialize()
    {
        $this->setConnectionService('dbTwo');
    }
}
