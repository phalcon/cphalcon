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

namespace Phalcon\Test\Fixtures\Forms;

use Phalcon\Forms\Form;

class SetActionForm extends Form
{
    public function initialize($entity = null, $options = null)
    {
        $this->setAction('/users/login');
    }
}
