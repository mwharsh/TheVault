import { Request, Response } from 'express';
import User from '../model/model';

export const createUser = async (req: Request, res: Response) => {
  try {
    const user = await User.create(req.body);
    res.status(201).json(user);
  } catch (error) {
    res.status(400).json({ error: 'Failed to create user', details: error });
  }
};

export const getUsers = async (_req: Request, res: Response) => {
  const users = await User.find();
  res.json(users);
};

export const updateUser = async (req: Request, res: Response): Promise<void> => {

    try {
      const user = await User.findByIdAndUpdate(
        req.params.id,
        req.body,
        { new: true, runValidators: true }
      );
  
      if (!user) {
        res.status(404).json({ message: 'User not found' });
      }
  
        res.json(user);
    } catch (error) {
      res.status(400).json({ error: 'Failed to update user', details: error });
    }

};

export const deleteUser = async (req: Request, res: Response): Promise<void> => {
    try {
      const user = await User.findByIdAndDelete(req.params.id);
      if (!user) res.status(404).json({ message: 'User not found' });
       res.status(204).send();
    } catch (error) {
       res.status(400).json({ error: 'Failed to delete user', details: error });
    }
  };

